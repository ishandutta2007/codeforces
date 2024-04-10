#include <iostream>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back

using namespace std;

int nn[100];
int cd[5][5];

main(){

		nn['R'] = 0;
		nn['G'] = 1;
		nn['B'] = 2;
		nn['Y'] = 3;
		nn['W'] = 4;

		int n;
		scanf("%d",&n);

		vector<pii> v;

		for(int i=0;i<n;i++){
			pii u;
			scanf(" %c%d",&u.first,&u.second);
			u.first = nn[u.first], u.second--;
			v.pb(u);
			cd[u.first][u.second]++;
		}

		int ans = 11;

		for(int i=0;i<(1<<5);i++)
			for(int j=0;j<(1<<5);j++){

				vector<set<pii> > possible;
				map<pii,int> tem;


				for(int k=0;k<n;k++){

					set<pii> st;
					int A=0, B=0;
					
					if(i & (1<<v[k].first)) A = 1;
					if(j & (1<<v[k].second)) B = 1;
					
					for(int ii=0;ii<5;ii++)
						for(int jj=0;jj<5;jj++){
							if(A && (ii != v[k].first))continue;
							if(B && (jj != v[k].second))continue;
							if(cd[ii][jj] == 0)continue;
							st.insert(pii(ii,jj));
						}

					possible.pb(st);
					tem[v[k]]++;
					if(i==0 && j==0)
						debug("%d %d\n",k,st.size());

				}

				int foi = 0;
				int ok = 1;

				while(foi < n && ok){
				
					ok = 0;
					int u = -1;
					for(int k=0;k<n;k++)
						if(possible[k].size() == 1)
						 u = k;

						if(i == 0 & j == 0)
							debug("foi %d u = %d\n",foi,u);
						 
					if(u+1)
						ok = 1;
					else
						continue;

					pii y = *(possible[u].begin());
					tem[y]--;
					possible[u].erase(y);
					if(tem[y] == 0)
						for(int k=0;k<n;k++)
							if(possible[k].find(y) != possible[k].end())
								possible[k].erase(y);
					foi++;
				}

				int qnt = 0;
				for(int k=0;k<5;k++){
					if(i & (1<<k))qnt++;
					if(j & (1<<k))qnt++;
				}

				if(ok)
					ans = min(ans, qnt);

			}

		printf("%d\n",ans);

}