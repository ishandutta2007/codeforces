# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int cnt1, cnt2, cnt3, cnt4;
bool check(){
	if (cnt3 > 0 && cnt1 == 0) return false;
	return cnt4 == cnt1;
}
int main(){
	scanf("%d%d%d%d", &cnt1, &cnt2, &cnt3, &cnt4);
	if (check()) printf("1\n");
	else printf("0\n");
	return 0;
}