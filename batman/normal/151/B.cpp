//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.3 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (300*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio(0);
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}

ifstream fin("input.txt");
ll n,k;
string s,ex;
map <string,ll> taxi,pizza,girl,index;
map <string,ll>::iterator it;
bool sortt(string x,string y){ return index[x] < index[y]; }
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k>>s;
        index[s]=i;
        taxi[s]=0;
        pizza[s]=0;
        girl[s]=0;
        for(int j=0;j<k;j++)
        {
            cin>>ex;
            if(ex[0]==ex[1] && ex[1]==ex[3] && ex[3]==ex[4] && ex[4]==ex[6] && ex[6]==ex[7])
                taxi[s]++;
            else if(ex[0]>ex[1] && ex[1]>ex[3] && ex[3]>ex[4] && ex[4]>ex[6] && ex[6]>ex[7])    
                pizza[s]++;
            else
                girl[s]++;  
        }
    }
    vector <string> ans;
    ll maxim=-1;
    for(it=taxi.begin();it!=taxi.end();it++)
        if(it->second > maxim)
            maxim= it->second;
    cout<<"If you want to call a taxi, you should call: ";      
    for(it=taxi.begin();it!=taxi.end();it++)
        if(it->second==maxim)
            ans.push_back(it->first);
    sort(ans.begin(),ans.end(),sortt);      
    for(int i=0;i<ans.size();i++)
    {
        if(i!=ans.size()-1)
            cout<<ans[i]<<", ";
        else
          cout<<ans[i]<<"."<<endl;  
    }
    vector <string> ans3;
    maxim=-1;
    for(it=pizza.begin();it!=pizza.end();it++)
        if(it->second>maxim)
            maxim=it->second;
    cout<<"If you want to order a pizza, you should call: ";        
    for(it=pizza.begin();it!=pizza.end();it++)
        if(it->second==maxim)
            ans3.push_back(it->first);
    sort(ans3.begin(),ans3.end(),sortt);        
    for(int i=0;i<ans3.size();i++)
    {
        if(i!=ans3.size()-1)
            cout<<ans3[i]<<", ";
        else
          cout<<ans3[i]<<"."<<endl; 
    }
    vector <string> ans2;
    maxim=-1;
    for(it=girl.begin();it!=girl.end();it++)
        if(it->second>maxim)
            maxim=it->second;
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";       
    for(it=girl.begin();it!=girl.end();it++)
        if(it->second==maxim)
            ans2.push_back(it->first);
    sort(ans2.begin(),ans2.end(),sortt);        
    for(int i=0;i<ans2.size();i++)
    {
        if(i!=ans2.size()-1)
            cout<<ans2[i]<<", ";
        else
          cout<<ans2[i]<<"."<<endl; 
    }
    return 0;
}