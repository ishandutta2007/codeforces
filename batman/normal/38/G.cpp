#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)101*1000)
#define SQ ((ll)350)

ll n,maxi[N/SQ+1000],fnsh,id[N],ex[N];
vector <ll> v[N/SQ+1000];

void reset()
{
	ll num=0;
	for(int i=0;i<fnsh;v[i].clear(),v[i].resize(0),i++)
		for(auto u:v[i])
			ex[num++]=u;
	fnsh=0;maxi[0]=0;
	for(int i=0;i<num;i++)
	{
		v[fnsh].push_back(ex[i]);maxi[fnsh]=max(maxi[fnsh],ex[i]);
		if(i%SQ==SQ-1 || i==num-1)fnsh++,maxi[fnsh]=0;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	ll a,c;
    	cin>>a>>c;
    	id[a]=i+1;
    	bool flg=0;
    	for(int j=0,num=0;j<fnsh && !flg;num+=(ll)v[j].size(),j++)
    		if(num+(ll)v[j].size()>c || maxi[j]>a)
    		{
    			flg=1;
    			for(int k=0;k<v[j].size();k++)
    			{
    				if(v[j][k]>a){v[j].insert(v[j].begin()+k,a);break;}
    				if(k+num==c){v[j].insert(v[j].begin()+k,a);maxi[j]=max(maxi[j],a);break;}
				}
			}
		if(!flg)
		{
			v[fnsh].push_back(a);
			maxi[fnsh]=a;
			fnsh++;
		}
		if(i%SQ==SQ-1)reset();
	}
	for(int i=fnsh-1;i>=0;i--)
		for(int j=(ll)v[i].size()-1;j>=0;j--)
			cout<<id[v[i][j]]<<" ";
    return 0;
}