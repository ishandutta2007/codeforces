#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
char s[N];
vector <int> v;

int main (int argc, char const *argv[]) {
    scanf("%d %s", &n, s + 1);

    int black = 0;
    for (int i = 1; i <= n; ++i) {
    	if (s[i] == 'B') ++black;
    	else {
    		if (black) v.push_back(black);
    		black = 0;
    	}
    }
	if (black) v.push_back(black);

    printf("%d\n", (int) v.size());
    for (int x : v) printf("%d ", x);
    puts("");
    return 0;
}