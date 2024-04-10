#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
char s1[1000];
char s2[1000];
char s3[1000];

int a[1000];
int main()
{
     int n1, n2, n3, i;
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    n1 = strlen(s1);
    n2 = strlen(s2);
    n3 = strlen(s3);
    for (i = 0; i < n1; i++)
        a[(int)s1[i]]++;
    for (i = 0; i < n2; i++)
        a[(int)s2[i]]++;
    for (i = 0; i < n3; i++)
        a[(int)s3[i]]--;
    for (i = 'a'; i <= 'z'; i++)
        if (a[i] != 0){
            printf("NO");
            return 0;
        }
    for (i = 'A'; i <= 'Z'; i++)
        if (a[i] != 0){
            printf("NO");
            return 0;
        }

    printf("YES");


    return 0;
}