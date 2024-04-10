/*
 * Words like "tomorrow" or "future" or "fate"
 *		No matter how far they extend their hands
 *			We breathe, we dream, we raise our love
 *				In a timeless land that is far out of reach
 */
#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define pii pair<int,int>
#define pb push_back
//#define int long long
typedef long long ll;
using namespace std;

const int N=500000;
const int lim=1000000000;
const int noofblocks=400;
ll a[N];
map<int,int>minind[noofblocks];
map<int,int>maxind[noofblocks];
int noofelem[noofblocks];
ll increment[noofblocks];
signed main()
{
	IO;
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		cin>>a[i];
	int tes=(n/noofblocks)+1;
	for(int i=n-1; i>=0; i--) {
		minind[i/tes][a[i]]=i;
		noofelem[i/tes]++;
	}
	for(int i=0; i<n; i++) {
		maxind[i/tes][a[i]]=i;
	}
	int te,l,r,x,y;
	for(int i=0; i<q; i++)
	{
		cin>>te;
		if(te==1)
		{
			cin>>l>>r>>x;
			l--;
			r--;
			int tel=l/tes,ter=r/tes;
			int teli=tel*tes,teri=ter*tes;
			if(tel==ter)
			{
				for(int i=teli; i<teli+noofelem[tel]; i++)
					a[i]+=increment[tel];
				for(int i=l; i<=r; i++)
					a[i]+=x;
				increment[tel]=0;
				minind[tel].clear();
				maxind[tel].clear();
				for(int i=teli+noofelem[tel]-1; i>=teli; i--)
					if(a[i]<=lim)
						minind[tel][a[i]]=i;
				for(int i=teli; i<teli+noofelem[tel]; i++)
					if(a[i]<=lim)
						maxind[tel][a[i]]=i;
			}
			else
			{
				for(int i=tel+1; i<ter; i++)
					increment[i]+=x;
				for(int i=teli; i<teli+noofelem[tel]; i++)
					a[i]+=increment[tel];
				increment[tel]=0;
				for(int i=l; i<teli+noofelem[tel]; i++)
					a[i]+=x;
				minind[tel].clear();
				maxind[tel].clear();
				for(int i=teli+noofelem[tel]-1; i>=teli; i--)
					if(a[i]<=lim)
						minind[tel][a[i]]=i;
				for(int i=teli; i<teli+noofelem[tel]; i++)
					if(a[i]<=lim)
						maxind[tel][a[i]]=i;

				for(int i=teri; i<teri+noofelem[ter]; i++)
					a[i]+=increment[ter];
				increment[ter]=0;
				for(int i=teri; i<=r; i++)
					a[i]+=x;
				minind[ter].clear();
				maxind[ter].clear();
				for(int i=teri+noofelem[ter]-1; i>=teri; i--)
					if(a[i]<=lim)
						minind[ter][a[i]]=i;
				for(int i=teri; i<teri+noofelem[ter]; i++)
					if(a[i]<=lim)
						maxind[ter][a[i]]=i;
			}
		}
		else
		{
			cin>>y;
			int mini=-1,maxi=-1;
			for(int i=0; i<noofblocks; i++)
				if(y-increment[i]>=0&&y-increment[i]<=lim&&minind[i].count(y-increment[i]))
				{
					mini=minind[i][y-increment[i]];
					break;
				}
			for(int i=noofblocks-1; i>=0; i--)
				if(y-increment[i]>=0&&y-increment[i]<=lim&&maxind[i].count(y-increment[i]))
				{
					maxi=maxind[i][y-increment[i]];
					break;
				}
			if(mini==-1)
				cout<<-1<<endl;
			else
				cout<<maxi-mini<<endl;
		}
	}
}