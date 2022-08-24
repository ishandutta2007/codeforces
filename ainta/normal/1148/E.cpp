#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;
#define pii pair<int,int>
int n, A[301000], B[301000];
long long SA[301000], SB[301000];
set<pii>S1;
struct Ans {
	int a, b, c;
};
vector<Ans>Res;
void Go(set<pii>::iterator it1, set<pii>::iterator it2, int x) {
	pii a = *it1, b = *it2;
	int t = min(abs(a.first - x), abs(b.first - x));
	S1.erase(it1);
	S1.erase(it2);
	Res.push_back({ a.second,b.second,t });
	S1.insert({ a.first + t,a.second });
	S1.insert({ b.first - t,b.second });
	S1.erase(S1.lower_bound({ x,-1 }));
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		S1.insert({ A[i],i });
	}
	for (i = 1; i <= n; i++) {
		scanf("%d", &B[i]);
	}
	sort(A + 1, A + n + 1);
	sort(B + 1, B + n + 1);
	for (i = 1; i <= n; i++) {
		SA[i] = SA[i - 1] + A[i];
		SB[i] = SB[i - 1] + B[i];
		if (SA[i] > SB[i]) {
			puts("NO");
			return 0;
		}
	}
	if (SA[n] != SB[n]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (i = 1; i <= n; i++) {
		auto it = S1.lower_bound({ B[i],-1 });
		if (it->first == B[i]) {
			S1.erase(it);
			continue;
		}
		else {
			auto it2 = it;
			it2--;
			Go(it2, it, B[i]);
		}
	}
	printf("%d\n", Res.size());
	for (auto &t : Res) {
		printf("%d %d %d\n", t.a, t.b, t.c);
	}
}