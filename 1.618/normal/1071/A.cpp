#include <bits/stdc++.h>
using namespace std;
vector <int> a1,a2;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int k = 1,suma = 0,sumb = 0;
	while(suma <= a){
		suma += k;
		k++;
	}
	k--;
	int oth = suma - a;
	for(int i=1;i<=k;i++) if(i != oth) a1.push_back(i);
	if(oth <= b){
		b -= oth;
		a2.push_back(oth);
		while(sumb <= b){
			k++;
			sumb += k;
			if(sumb <= b) a2.push_back(k);
		}
	}
	printf("%d\n",(int)a1.size());
	for(int i=0;i<(int)a1.size();i++){
		printf("%d%c",a1[i],i == a1.size() - 1 ? '\n' : ' ');
	}
	printf("%d\n",(int)a2.size());
	for(int i=0;i<(int)a2.size();i++){
		printf("%d%c",a2[i],i == a2.size() - 1 ? '\n' : ' ');
	}
	return 0;
}