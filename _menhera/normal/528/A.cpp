#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int main()
{
	int W,H,N;
	scanf("%d%d%d",&W,&H,&N);
	set<int>h;
	h.insert(0);
	h.insert(H);
	multiset<int>hh;
	hh.insert(H);
	set<int>w;
	w.insert(0);
	w.insert(W);
	multiset<int>ww;
	ww.insert(W);
	for(int i=0;i<N;i++)
	{
		char buf[123];
		int t;
		scanf("%s%d",buf,&t);
		if(buf[0]=='H')
		{
			set<int>::iterator it=h.lower_bound(t);
			set<int>::iterator it2=it;
			it2--;
			int itv=*it;
			int it2v=*it2;
			h.insert(t);
			hh.erase(hh.find(itv-it2v));
			hh.insert(itv-t);
			hh.insert(t-it2v);
		}
		else
		{
			set<int>::iterator it=w.lower_bound(t);
			set<int>::iterator it2=it;
			it2--;
			int itv=*it;
			int it2v=*it2;
			w.insert(t);
			ww.erase(ww.find(itv-it2v));
			ww.insert(itv-t);
			ww.insert(t-it2v);		
		}
		set<int>::iterator www=ww.end();
		www--;
		set<int>::iterator hhh=hh.end();
		hhh--;
		printf("%lld\n",1LL*(*www)*(*hhh));
	}
	return 0;
}