#include <cstdio>
#include <algorithm>
using namespace std;

char mat[10][10];

int get_w(int x, int y) {
    for (int i = x - 1; i >= 0; i--)
        if (mat[i][y] != '.') return 10;
    return x;
}

int get_b(int x, int y) {
    for (int i = x + 1; i < 8; i++)
        if (mat[i][y] != '.') return 10;
    return 7 - x;
}

int main() {
    for (int i = 0; i < 8; i++)
        scanf("%s", mat[i]);
       
    int w = 10, b = 10;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (mat[i][j] == 'W') w = min(w, get_w(i, j));
            else if (mat[i][j] == 'B') b = min(b, get_b(i, j));
    
    puts(w <= b ? "A" : "B");
    return 0;
}