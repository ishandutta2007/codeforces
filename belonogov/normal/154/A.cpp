#include <iostream>
#include <cstdio>

using namespace std;

string s;
char a[100][100];


int main()
{
   int k, i, j, n, cnt = 0, k1, k2;
    cin >> s;
    n = s.length();
    cin >> k;
    for (i = 0; i < k; i++)
        scanf("%s", a[i]);

    for (j = 0; j < k; j++){
        k1 = 0;
        k2 = 0;
        for (i = 0; i < n; i++){
            if (s[i] != a[j][0] && s[i] != a[j][1]){
                cnt += min(k1, k2);
                k1 = 0;
                k2 = 0;
                continue;
            }
            if (s[i] == a[j][0])
                k1++;
            if (s[i] == a[j][1])
                k2++;

        }
        cnt += min(k1, k2);
    }


    cout << cnt;
    return 0;
}