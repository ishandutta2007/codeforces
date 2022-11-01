#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
char s[N];

int main (int argc, char const *argv[]) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    
    int i = 1;
    while (i <= n and s[i] == 'a') ++i;
    
    if (i == n + 1) {
    	s[n] = 'z';
    	printf("%s\n", s + 1);
    	return 0;
    }

    int j = i;
    while (j <= n and s[j] != 'a') s[j] = s[j] - 1, ++j;
    printf("%s\n", s + 1);
    return 0;
}