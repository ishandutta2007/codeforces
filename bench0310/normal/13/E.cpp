#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    const int N=100000;
    int p[N],next[N],j[N];
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> p[i];
    int sz=0;
    while(sz*sz<=n) sz++; sz--;
    for(int i=n-1;i>=0;i--)
    {
        if(i+p[i]>=n)
        {
            next[i]=-1;
            j[i]=1;
        }
        else if(((i+p[i])/sz)==(i/sz))
        {
            next[i]=next[i+p[i]];
            j[i]=j[i+p[i]]+1;
        }
        else
        {
            next[i]=i+p[i];
            j[i]=1;
        }
    }
    int type,idx,pw;
    for(int a=0;a<m;a++)
    {
        cin >> type >> idx;
        idx--;
        if(type==0)
        {
            cin >> pw;
            p[idx]=pw;
            for(int i=idx;i>=(idx/sz)*sz;i--)
            {
                if(i+p[i]>=n)
                {
                    next[i]=-1;
                    j[i]=1;
                }
                else if(((i+p[i])/sz)==(i/sz))
                {
                    next[i]=next[i+p[i]];
                    j[i]=j[i+p[i]]+1;
                }
                else
                {
                    next[i]=i+p[i];
                    j[i]=1;
                }
            }
        }
        else
        {
            int cnt=0;
            while(next[idx]!=-1)
            {
                cnt+=j[idx];
                idx=next[idx];
            }
            while(j[idx]>1)
            {
                idx+=p[idx];
                cnt++;
            }
            cout << idx+1 << " " << cnt+1 << endl;
        }
    }
    return 0;
}