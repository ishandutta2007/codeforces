#include<bits/stdc++.h>
using namespace std;

int A[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int Func (int N) {
    int k, Ret = 0;
    while (N) {
        k = N % 10;
        Ret += A[k];
        N /= 10;
    }
    return Ret;
}

int main() {
	int Res = 0, a, b, i;
    cin >> a >> b;
    for(i = a; i <= b; i++) Res += Func(i); 
    cout << Res << endl;
}