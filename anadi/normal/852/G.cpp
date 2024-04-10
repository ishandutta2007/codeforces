#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll mod_1=1e9+7;
const ll mod_2=1e9+9;
const ll podst=29;
int n,m;
ll pot_1[N],pot_2[N];
map<pair<ll,ll>,int> xd;
char s[N];
int main()
{
  pot_1[0]=1; for(int i=1; i<N; ++i) pot_1[i]=(pot_1[i-1]*podst)%mod_1;
  pot_2[0]=1; for(int i=1; i<N; ++i) pot_2[i]=(pot_2[i-1]*podst)%mod_2;
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; ++i)
  {
    scanf("%s",s); int l=strlen(s);
    ll hasz_1=0, hasz_2=0;
    for(int i=l-1; i>=0; --i)
    {
      hasz_1=(hasz_1*podst+s[i]-'a'+1)%mod_1;
      hasz_2=(hasz_2*podst+s[i]-'a'+1)%mod_2;
    }
    xd[{hasz_1,hasz_2}]++;    
    //printf("> %lld %lld\n",hasz_1,hasz_2);
  }
  for(int i=1; i<=m; ++i)
  {
    scanf("%s",s); int l=strlen(s);
    ll hasz_1=0, hasz_2=0;
    vector<int> gdz;
    for(int i=l-1; i>=0; --i) if(s[i]=='?') gdz.push_back(i);
    if(gdz.size()==0)
    {
      ll hasz_1=0, hasz_2=0;
      for(int i=l-1; i>=0; --i)
      {
        hasz_1=(hasz_1*podst+s[i]-'a'+1)%mod_1;
        hasz_2=(hasz_2*podst+s[i]-'a'+1)%mod_2;
      }
      printf("%d\n",xd[{hasz_1,hasz_2}]);
    }
    if(gdz.size()==1)
    {
      int res=0;
      vector<pair<ll,ll>> elo;
      for(char z='a'; z<='f'; ++z)
      {
        ll hasz_1=0, hasz_2=0;
        for(int i=l-1; i>=0; --i)
        {
          if(i==gdz[0])
          {        
            if(z!='f')
            {
              hasz_1=(hasz_1*podst+z-'a'+1)%mod_1;
              hasz_2=(hasz_2*podst+z-'a'+1)%mod_2;
            }
          }
          else
          {
            hasz_1=(hasz_1*podst+s[i]-'a'+1)%mod_1;
            hasz_2=(hasz_2*podst+s[i]-'a'+1)%mod_2; 
          }
        }
        elo.push_back({hasz_1,hasz_2});
      }
      sort(elo.begin(), elo.end()); 
      pair<ll,ll> ostatni={-1,-1};
      for(auto e:elo)
      {
        if(e!=ostatni) res+=xd[e];
        ostatni=e;
      }
      printf("%d\n",res);
    }
    if(gdz.size()==2) /* ------------------------------------------------------------------------------------------------------------ */
    {
      int res=0;
      vector<pair<ll,ll>> elo;
      for(char z='a'; z<='f'; ++z) for(char x='a'; x<='f'; ++x)
      {
        ll hasz_1=0, hasz_2=0;
        for(int i=l-1; i>=0; --i)
        {
          if(i==gdz[0])
          {        
            if(z!='f')
            {
              hasz_1=(hasz_1*podst+z-'a'+1)%mod_1;
              hasz_2=(hasz_2*podst+z-'a'+1)%mod_2;
            }
          }
          else
          {
            if(i==gdz[1])
            {
              if(x!='f')
              {
                hasz_1=(hasz_1*podst+x-'a'+1)%mod_1;
                hasz_2=(hasz_2*podst+x-'a'+1)%mod_2;      
              }
            }
            else
            {
              hasz_1=(hasz_1*podst+s[i]-'a'+1)%mod_1;
              hasz_2=(hasz_2*podst+s[i]-'a'+1)%mod_2; 
            }
          }
        }   
        elo.push_back({hasz_1,hasz_2});
      }
      sort(elo.begin(), elo.end()); 
      pair<ll,ll> ostatni={-1,-1};
      for(auto e:elo)
      {
        if(e!=ostatni) res+=xd[e];
        ostatni=e;
      }
      printf("%d\n",res);
    }
    if(gdz.size()==3) /* ----------------------------------------------------------------------------------------------------------- */
    {
      int res=0;
      vector<pair<ll,ll>> elo;
      for(char z='a'; z<='f'; ++z) for(char x='a'; x<='f'; ++x) for(char c='a'; c<='f'; ++c)
      {
        ll hasz_1=0, hasz_2=0;
        for(int i=l-1; i>=0; --i)
        {
          if(i==gdz[0])
          {        
            if(z!='f')
            {
              hasz_1=(hasz_1*podst+z-'a'+1)%mod_1;
              hasz_2=(hasz_2*podst+z-'a'+1)%mod_2;
            }
          }
          else
          {
            if(i==gdz[1])
            {
              if(x!='f')
              {
                hasz_1=(hasz_1*podst+x-'a'+1)%mod_1;
                hasz_2=(hasz_2*podst+x-'a'+1)%mod_2;      
              }
            }
            else
            {
              if(i==gdz[2])
              {
                if(c!='f')
                {
                  hasz_1=(hasz_1*podst+c-'a'+1)%mod_1;
                  hasz_2=(hasz_2*podst+c-'a'+1)%mod_2;      
                }
              }
              else
              {
                hasz_1=(hasz_1*podst+s[i]-'a'+1)%mod_1;
                hasz_2=(hasz_2*podst+s[i]-'a'+1)%mod_2; 
              }
            }
          }
        }
        elo.push_back({hasz_1,hasz_2});
      }
      sort(elo.begin(), elo.end()); 
      pair<ll,ll> ostatni={-1,-1};
      for(auto e:elo)
      {
        if(e!=ostatni) res+=xd[e];
        ostatni=e;
      }
      printf("%d\n",res);
    }
  }
	return 0;
}