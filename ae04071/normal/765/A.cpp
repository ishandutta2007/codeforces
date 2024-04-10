#include <stdio.h>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#define mp std::make_pair

int n;
char str[10];
char tmp[30];

int cnt[200];
std::map<std::string, int> arr;

int main(){
	scanf("%d",&n);
	scanf("%s",str);
	std::string now=str, home=str;
	int tt=1;
	arr.insert(mp(home, 0));
	for(int i=0;i<n;i++) {
		scanf("%s",tmp);
		std::string a,b;
		for(int i=0;i<3;i++)
			a.push_back(tmp[i]);
		for(int i=5;i<8;i++)
			b.push_back(tmp[i]);
		
		auto it=arr.find(a);
		if(it==arr.end()) {
			arr.insert(mp(a, tt++));
			it=arr.find(a);
		}
		auto jt=arr.find(b);
		if(jt==arr.end()) {
			arr.insert(mp(b, tt++));
			jt=arr.find(b);
		}
		if(a==home) {
			int idx=jt->second;
			if(cnt[idx]<1) cnt[idx]=1;
		}
		else if(b==home) {
			int idx=it->second;
			if(cnt[idx]<2) cnt[idx]=2;
		}
	}

	if(n&1) printf("contest\n");
	else printf("home\n");
	return 0;

	for(int i=1;i<tt;i++) {
		if(cnt[i]==1){
		 	printf("contest\n");
		 	return 0;
		}
	}
	printf("home\n");
	return 0;
}