#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	for(int i=a;i>=1;i--){
		if(i <= a && i + 1 <= b && i + 2 <= c){
			printf("%d\n",i * 3 + 3);
			return 0;
		}
	}
	return 0;
}