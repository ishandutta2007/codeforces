#include <stdio.h>
#include <cstring>
#include <map>

int n,m;
int cnt[5010][1010][2];
std::map<std::string, int> map;
char t1[1010], t2[1010], t3[1010];

int main() {
	scanf("%d %d",&n,&m);
	for(int j=0;j<m;j++) {
		cnt[n+1][j][1]=1;
	}
	map["?"]=n+1;
	for(int i=1;i<=n;i++) {
		scanf("%s",t1);
		map[t1]=i;
		scanf("%s",t1);
		scanf("%s",t1);
		if(t1[0]=='0'||t1[0]=='1') {
			for(int j=0;j<m;j++) {
				cnt[i][j][0]=cnt[i][j][1]=t1[j]-'0';
			}
			continue;
		}
		scanf("%s %s", t2, t3);
		int i1=map[t1], i2=map[t3];
		if(!strcmp(t2, "AND")) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<2;k++) {
					cnt[i][j][k]=cnt[i1][j][k]&cnt[i2][j][k];
				}
			}
		}
		else if(!strcmp(t2, "OR")) {
			for(int j=0;j<m;j++) {
				for(int k=0;k<2;k++) {
					cnt[i][j][k]=cnt[i1][j][k]|cnt[i2][j][k];
				}
			}
		}
		else {
			for(int j=0;j<m;j++) {
				for(int k=0;k<2;k++) {
					cnt[i][j][k]=cnt[i1][j][k]^cnt[i2][j][k];
				}
			}
		}
	}

	for(int j=0;j<m;j++) {
		int s1=0, s2=0;
		for(int i=1;i<=n;i++) {
			s1+=cnt[i][j][0]; s2+=cnt[i][j][1];
		}
		if(s1<=s2) printf("0");
		else printf("1");
	}
	puts("");
	for(int j=0;j<m;j++) {
		int s1=0, s2=0;
		for(int i=0;i<=n;i++) {
			s1+=cnt[i][j][0]; s2+=cnt[i][j][1];
		}
		if(s1>=s2) printf("0");
		else printf("1");
	}
	return 0;
}