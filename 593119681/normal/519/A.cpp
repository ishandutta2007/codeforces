#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int A[10086], ans1, ans2;

int main()
{
    A['q'] = 9, A['r'] = 5, A['b'] = A['n'] = 3, A['p'] = 1;
    char ch = '\n';
    for (int i = 1; i <= 64; i ++) 
    {
        while (ch != '.' && ch != 'q' && ch != 'r' && ch != 'k' && ch != 'n' && ch != 'N' && ch != 'p' && ch != 'b' && ch != 'Q' && ch != 'R' && ch != 'K' && ch != 'P' && ch != 'B')
            ch = getchar();
        if (ch >= 'a' && ch <= 'z') ans1 += A[ch];
            else if (ch >= 'A' && ch <= 'Z') ans2 += A[ch - 'A' + 'a'];
        ch = getchar();
    }
    puts(ans1 > ans2 ? "Black" : (ans1 == ans2 ? "Draw" : "White"));
    return 0;
}

//the queen's weight is 9,
//the rook's weight is 5,
//the bishop's weight is 3,
//the knight's weight is 3,
//the pawn's weight is 1,