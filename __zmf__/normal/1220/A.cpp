#include<bits/stdc++.h>
using namespace std;
int n;
char a[100009];
int cnt[509];
int main() 
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++)cnt[a[i]]++;
	for(int i=1;i<=cnt['n'];i++)printf("%d ",1);
	for(int i=1;i<=cnt['z'];i++)printf("%d ",0);
    return 0;
}
/*
11 11
1 6
2 6
3 6
4 6
5 6
6 6
7 11
7 10
7 9
7 8
7 7
*/