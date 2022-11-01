#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char c[4000001];
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<string> v(n);
        set<string> s;
        vector<int> b(4,0);
        for(int i=0;i<n;i++)
        {
            scanf("%s",c);
            v[i]=c;
            s.insert(v[i]);
            b[2*(v[i][0]-'0')+(v[i].back()-'0')]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(v[i][0]==v[i].back()) continue;
            int m=2*(v[i][0]-'0')+(v[i].back()-'0');
            string t=v[i];
            reverse(t.begin(),t.end());
            if(b[m]>b[3-m]+1&&s.find(t)==s.end())
            {
                res.push_back(i);
                b[m]--;
                b[3-m]++;
            }
        }
        if((b[0]>0&&b[3]>0&&b[1]==0&&b[2]==0)||(abs(b[1]-b[2])>1)) printf("-1\n");
        else
        {
            printf("%d\n",(int)res.size());
            for(int a:res) printf("%d ",a+1);
            printf("\n");
        }
    }
    return 0;
}