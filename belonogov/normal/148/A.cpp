#include <iostream>
#include <cstdio>

using namespace std;
int b[10];
bool use[10];
int n, cnt = 0;

int evkl(int a, int b){
    if (b != 0)
        return evkl(b, a % b);
    return a;
}
void rec(int k){
    int i, z, d;
    if (k >= 4){
        z = 0;
        d = -1;
        for (i = 0; i < 4; i++)
            if (use[i]){
                if (d == -1)
                    d = b[i];
                else
                    d = (b[i] * d) / evkl(b[i], d);
                z++;
            }
        if (z == 0)
            return;
        if (z % 2 == 1)
            cnt += n / d;
        else
            cnt -= n / d;
        return;
    }
    rec(k + 1);
    use[k] = 1;
    rec(k + 1);
    use[k] = 0;

}

int main()
{
   cin >> b[0] >> b[1] >> b[2] >> b[3] >> n;
    rec(0);
    cout << cnt;
    return 0;
}