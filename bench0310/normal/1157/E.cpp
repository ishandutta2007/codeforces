#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	multiset<int> s;
	for(int i=0;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        s.insert(b);
    }
    for(int i=0;i<n;i++)
    {
        multiset<int>::iterator it=s.lower_bound(n-a[i]);
        if(it==s.end()) it=s.begin();
        printf("%d ",(a[i]+*it)%n);
        s.erase(it);
    }
    printf("\n");
	return 0;
}