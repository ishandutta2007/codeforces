////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int n,p,lastscore[1100];
pair <int,string> input[1100],res[1100];
vector <string> ans;
int main()
{ 

    cin>>n;
    for(int i=0;i<n;i++)
    {
        int q=0;
        cin>>input[i].second>>input[i].first;
        string s=input[i].second;
        int sc=input[i].first;
        for(int j=0;j<p;j++)
            if(res[j].second==s)
            {
                q++;
                res[j].first+=sc;
                break;
            }
        if(q==0)
        {
            res[p].second=s;
            res[p].first=sc;
            p++;
        }   
    }
    sort(res,res+p);
    int sc=res[p-1].first;
    for(int i=p-1;i>=0 && res[i].first==sc;i--)
        ans.push_back(res[i].second);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<ans.size();j++)
            if(ans[j]==input[i].second)
            {
                lastscore[j]+=input[i].first;
                if(lastscore[j]>=sc)
                {
                    cout<<ans[j]<<endl;
                    return 0;
                }   
                break;
            }
    
    return 0;
}