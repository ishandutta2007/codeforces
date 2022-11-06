#include <cstdio>

using namespace std;

char a[105],b[105];
long n,m,pr[105],q,i,gasit = 0;
long ap[2]['z'+10];

int main()
{
    scanf("%s\n",a+1);
    scanf("%s",b+1);

    n = 0;
    while (a[n+1] != '\0') { n++; ap[0][a[n]]++; };
    m = 0;
    while (b[m+1] != '\0') { m++; ap[1][b[m]]++; };

    q = 1;
    for (i=1;i<=n;i++) {
        if (a[i] == b[q]) {
            q++;
            if (q == m+1) {
                break;
            }
        }
    }
    gasit = (q == m+1);

    if (gasit) {
        printf("automaton");
    } else {
        gasit = 1;
        for(i='a';i<='z';i++) {
            if (ap[0][i] < ap[1][i]) {
                gasit = 0;
                break;
            }
        }
        if (gasit) {
            if (n == m)
                printf("array");
            else{
                printf("both");
            }
        } else {
                printf("need tree");
        }
    }

    return 0;
}