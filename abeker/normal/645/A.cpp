#include <cstdio>
#include <string>
using namespace std;

const int x[] = {0, 0, 1, 1};
const int y[] = {0, 1, 1, 0};

char a[5][5], b[5][5];

void add(string &s, char c ) {
    if (c != 'X') s += c;
}

int main() {
    for (int i = 0; i < 2; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < 2; i++)
        scanf("%s", b[i]);
        
    string A = "";
    for (int i = 0; i < 4; i++) 
        if (a[x[i]][y[i]] == 'A') {
            for (int j = 0; j < 4; j++)
                add(A, a[x[(i + j) % 4]][y[(i + j) % 4]]);
            break;
        }
    
    string B = "";
    for (int i = 0; i < 4; i++) 
        if (b[x[i]][y[i]] == 'A') {
            for (int j = 0; j < 4; j++)
                add(B, b[x[(i + j) % 4]][y[(i + j) % 4]]);
            break;
        }
    
    puts(A == B ? "YES" : "NO");
    
    return 0;
}