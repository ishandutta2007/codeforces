#include <cstdio>
#include <algorithm>
#include <stack>

#define M 100100

using namespace std;

int n,a[M],ans=0;
stack<int> s;

void read(void){
	scanf("%d",&n);
	for (int i=0; i<n; ++i)
	scanf("%d",a+i);
}

void kill(void){
	while (!s.empty())
	s.pop();
	for (int i=0; i<n; ++i){
		while (!s.empty() && s.top()<a[i])
		ans=max(ans,(a[i]^s.top())),s.pop();
		s.push(a[i]);
	}
}

int main()
{
	read();
	kill();
	reverse(a,a+n);
	kill();
	printf("%d\n",ans);
	return 0;
}