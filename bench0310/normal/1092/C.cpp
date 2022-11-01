#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[210];
    vector<string> v[n];
    int id[n][2];
    for(int i=0;i<2*n-2;i++)
    {
        cin >> s[i];
        v[s[i].size()].push_back(s[i]);
        id[s[i].size()][v[s[i].size()].size()-1]=i;
    }
    int pf[210],sf[210];
    for(int i=0;i<210;i++) pf[i]=sf[i]=-1;
    bool good=1;
    for(int i=1;i<n-1;i++)
    {
        if(v[n-1][0][i]!=v[n-1][1][i-1])
        {
            good=0;
            break;
        }
    }
    string res;
    if(good)
    {
        res=v[n-1][0]+v[n-1][1][n-2];
        pf[n-1]=id[n-1][0];
        sf[n-1]=id[n-1][1];
    }
    else
    {
        res=v[n-1][1]+v[n-1][0][n-2];
        pf[n-1]=id[n-1][1];
        sf[n-1]=id[n-1][0];
    }
    for(int o=1;o<n-1;o++)
    {
        int len=o;
        bool pfsut[2],sfsut[2];
        pfsut[0]=pfsut[1]=sfsut[0]=sfsut[1]=1;
        for(int a=0;a<2;a++)
        {
            for(int i=0;i<len;i++)
            {
                if(v[len][a][i]!=res[i])
                {
                    pfsut[a]=0;
                    break;
                }
            }
            int idx=n-len;
            for(int i=0;i<len;i++)
            {
                if(v[len][a][i]!=res[idx])
                {
                    sfsut[a]=0;
                    break;
                }
                idx++;
            }
        }
        if(pfsut[0]&&sfsut[1])
        {
            pf[len]=id[len][0];
            sf[len]=id[len][1];
        }
        else if(pfsut[1]&&sfsut[0])
        {
            pf[len]=id[len][1];
            sf[len]=id[len][0];
        }
    }
    string ans;
    for(int o=0;o<2*n-2;o++)
    {
        for(int i=1;i<=n-1;i++)
        {
            if(pf[i]==o)
            {
                ans+='P';
                break;
            }
            if(sf[i]==o)
            {
                ans+='S';
                break;
            }
        }
    }
    if((int)ans.size()==2*n-2) cout << ans << endl;
    else
    {
        res=v[n-1][1]+v[n-1][0][n-2];
        pf[n-1]=id[n-1][1];
        sf[n-1]=id[n-1][0];
        for(int o=1;o<n-1;o++)
        {
            int len=o;
            bool pfsut[2],sfsut[2];
            pfsut[0]=pfsut[1]=sfsut[0]=sfsut[1]=1;
            for(int a=0;a<2;a++)
            {
                for(int i=0;i<len;i++)
                {
                    if(v[len][a][i]!=res[i])
                    {
                        pfsut[a]=0;
                        break;
                    }
                }
                int idx=n-len;
                for(int i=0;i<len;i++)
                {
                    if(v[len][a][i]!=res[idx])
                    {
                        sfsut[a]=0;
                        break;
                    }
                    idx++;
                }
            }
            if(pfsut[0]&&sfsut[1])
            {
                pf[len]=id[len][0];
                sf[len]=id[len][1];
            }
            else if(pfsut[1]&&sfsut[0])
            {
                pf[len]=id[len][1];
                sf[len]=id[len][0];
            }
        }
        string ans;
        for(int o=0;o<2*n-2;o++)
        {
            for(int i=1;i<=n-1;i++)
            {
                if(pf[i]==o)
                {
                    ans+='P';
                    break;
                }
                if(sf[i]==o)
                {
                    ans+='S';
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}