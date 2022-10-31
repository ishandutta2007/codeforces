#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005;
int n,i,ans;
int main(){
	scanf("%d",&n);
	for(i=2;i<n;i++)
		ans+=i*(i+1);
	cout<<ans;
}