#include <cstdio>
#include <cstring>
#include <cctype>

char str[100];
int main()
{
    gets(str);
    int a;
    scanf("%d", &a);
    for(int i=0; i<strlen(str);i++)
        str[i]=tolower(str[i]);
        
    for (int i =0; i <strlen(str);i++)
    {
        char c=str[i];
        if(c<a+97)
        {
            printf("%c",toupper(c));
        }
        else
        printf("%c",tolower(c));
    }
}