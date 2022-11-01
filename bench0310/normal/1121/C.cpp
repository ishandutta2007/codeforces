#include <bits/stdc++.h>

using namespace std;

int syst(double m,double n)
{
    return (int)((100.0*m/n)+0.5);
}

int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int idx=0;
    int m=0;
    int e[k],id[k]; //The end of current testing, -1 if empty || id of problem that is being tested
    for(int i=0;i<k;i++) e[i]=id[i]=-1;
    int res=0;
    vector<bool> interesting(n,0);
    for(int i=0;i<min(n,k);i++)
    {
        e[i]=a[i];
        id[i]=i;
        idx++;
    }
    for(int o=1;o<=150000;o++)
    {
        //Update
        for(int i=0;i<k;i++)
        {
            if(e[i]==o)
            {
                m++;
                if(idx<n)
                {
                    e[i]+=a[idx];
                    id[i]=idx;
                    idx++;
                }
                else e[i]=-1;
            }
        }
        //Check
        int q=syst(m,n);
        bool done=1;
        for(int i=0;i<k;i++)
        {
            if(e[i]==-1) continue;
            done=0;
            if((o-(e[i]-a[id[i]])+1)==q&&interesting[id[i]]==0)
            {
                /*cout << "time: " << o << ".5" << endl;
                cout << "end at: " << e[i] << endl;
                cout << "required time: " << a[id[i]] << endl;
                cout << m << " of " << n << " solutions tested for q=" << q << endl;
                cout << "currently testing " << (o-(e[i]-a[id[i]])+1) << endl;
                cout << endl;*/
                interesting[id[i]]=1;
                res++;
            }
        }
        if(done) break;
    }
    cout << res << endl;
    return 0;
}