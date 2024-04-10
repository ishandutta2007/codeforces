#include <stdio.h>
#include <utility>
#include <algorithm>

typedef std::pair<int, int> ip;
int n,m,k;
ip have[1000001], use[1000001];
int chk[1000001];
int ccnt[10000001];
bool vis[1000001];

bool Check(int day)
{
	std::fill(vis+1, vis+m+1, false);

	int cnt=0, hi=1;
	for(int i=1;i<=m;i++) {
		while(use[i].first>=have[hi].first && hi<=n) {
			cnt++; hi++;
		}
		if(cnt/k==use[i].first) {
			cnt++; vis[i]=true;
		}
		if(cnt>=(day+1ll)*k) break;
	}
	if(cnt>=(day+1ll)*k) {
		int idx=1, cnt=0;
		for(int i=1;i<=m && cnt<(day+1ll)*k-n;i++) {
			if(vis[i])  {
				chk[idx++]=use[i].second;
				cnt++;
			}
		}
		return true;
	}
	else
		return false;
}

int main()
{

	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&have[i].first);
		have[i].second=i;
	}
	for(int j=1;j<=m;j++) {
		scanf("%d",&use[j].first);
		use[j].second=j;
	}

	std::sort(have+1, have+n+1);
	std::sort(use+1, use+m+1);

	int cnt=0;
	for(int i=1;i<=n;i++) {
		cnt++;
		if((cnt-1)/k>have[i].first) {
			printf("-1\n");
			return 0;
		}
	}

	cnt=0;
	for(int i=1;i<=n;i++) {
		cnt++;
		if(i==n || have[i].first!=have[i+1].first) {
			if(cnt>k) {
				ccnt[have[i].first]=k;

				int t=have[i].first-1;
				int idx=i-cnt;
				cnt-=k;
				while(cnt) {
					if(ccnt[t]>=k) {
						t--;
						continue;
					}
					have[idx--].first=t;
					ccnt[t]++;
					cnt--;
				}
			}
			else
				ccnt[have[i].first]=cnt;
			cnt=0;
		}
	}

	int idx=0;
	int t=0;
	for(int i=1;i<=m;i++) {
		while(ccnt[t]>=k) t++;
		if(t>use[i].first) continue;
		if(ccnt[t]<k) {
			chk[idx++]=use[i].second;
			ccnt[t]++;
		}
	}

	printf("%d\n", idx);
	std::sort(chk, chk+idx);
	for(int i=0;i<idx;i++) {
		printf("%d ",chk[i]);
	}

	return 0;
}