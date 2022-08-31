#include<cstdio>
#include<algorithm>
#define N_ 1010000
using namespace std;
char p[N_], A[N_], B[N_];
int i, n, K, TC, w[26], vis[26], ow[26], ovis[26];
void Print() {
	int i, j;
	for (i = 0; i < 26; i++) {
		if (w[i] != -1)continue;
		for (j = 0; j < 26; j++) {
			if (vis[j] == -1) break;
		}
		w[i] = j;
		vis[j] = i;
	}
	puts("YES");
	for (i = 0; i < K; i++)printf("%c", w[i]+'a');
	puts("");
}
bool PosA(int be) {
	int i, j;
	for (i = 0; i < 26; i++) {
		ow[i] = w[i], ovis[i] = vis[i];
	}
	for (i = be; i < n; i++) {
		int t = w[p[i] - 'a'];
		if (t == -1) {
			for (j = K - 1; j >= 0; j--) {
				if (vis[j] == -1)break;
			}
			w[p[i] - 'a'] = j;
			vis[j] = p[i] - 'a';
		}
		if (w[p[i] - 'a'] != A[i] - 'a') {
			if (w[p[i] - 'a'] < A[i] - 'a') {
				for (i = 0; i < 26; i++) {
					w[i] = ow[i], vis[i] = ovis[i];
				}
				return false;
			}
			Print();
			return true;
		}
	}
	Print();
	for (i = 0; i < 26; i++) {
		w[i] = ow[i], vis[i] = ovis[i];
	}
	return true;
}
bool PosB(int be) {
	int i, j;
	for (i = 0; i < 26; i++) {
		ow[i] = w[i], ovis[i] = vis[i];
	}
	for (i = be; i < n; i++) {
		int t = w[p[i] - 'a'];
		if (t == -1) {
			for (j = 0; j < K; j++) {
				if (vis[j] == -1)break;
			}
			w[p[i] - 'a'] = j;
			vis[j] = p[i] - 'a';
		}
		if (w[p[i] - 'a'] != B[i] - 'a') {
			if (w[p[i] - 'a'] > B[i] - 'a') {
				for (i = 0; i < 26; i++) {
					w[i] = ow[i], vis[i] = ovis[i];
				}
				return false;
			}
			Print();
			return true;
		}
	}
	Print();
	for (i = 0; i < 26; i++) {
		w[i] = ow[i], vis[i] = ovis[i];
	}
	return true;
}
void Do() {
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < 26; i++)w[i] = -1, vis[i] = -1;
	int j;
	for (i = 0; i < n; i++) {
		if (A[i] == B[i]) {
			if (w[p[i] - 'a'] != -1 && w[p[i] - 'a'] != A[i] - 'a') {
				puts("NO");
				return;
			}
			if (vis[A[i] - 'a'] != -1 && vis[A[i] - 'a'] != p[i] - 'a') {
				puts("NO");
				return;
			}
			w[p[i] - 'a'] = A[i] - 'a';
			vis[A[i] - 'a'] = p[i] - 'a';
			continue;
		}
		int t = w[p[i] - 'a'];
		if (t == -1) {
			for (j = A[i] - 'a'; j <= B[i] - 'a'; j++) {
				if (vis[j] != -1)continue;
				w[p[i] - 'a'] = j, vis[j] = p[i] - 'a';
				if (j == A[i] - 'a') {
					if (PosA(i + 1))return;
				}
				else if (j == B[i] - 'a') {
					if (PosB(i + 1))return;
				}
				else {
					Print();
					return;
				}
				w[p[i] - 'a'] = -1, vis[j] = -1;
			}
			puts("NO");
			return;
		}
		else {
			if (A[i] - 'a' > t || B[i]-'a' < t) {
				puts("NO");
				return;
			}
			if (t == A[i] - 'a') {
				if (PosA(i + 1))return;
				else puts("NO");
				return;
			}
			else if (t == B[i] - 'a') {
				if (PosB(i + 1))return;
				else puts("NO");
				return;
			}
			else {
				Print();
				return;
			}
		}
	}
	Print();
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &K);
		scanf("%s%s%s", p, A, B);
		Do();
	}
}