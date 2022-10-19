/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[200100],res;
vector<int>_0,_1;
void mina(){
	scanf("%d",&n),res=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)_0.push_back(i);
		else _1.push_back(i);
	}
	reverse(_1.begin(),_1.end());
	while(!_0.empty()&&!_1.empty()&&_0.back()>_1.back())_1.pop_back(),_0.pop_back(),res++;
	_0.clear(),_1.clear();
	printf("%d\n",res);
}
int T;
int main(){scanf("%d",&T);while(T--)mina();return 0;}