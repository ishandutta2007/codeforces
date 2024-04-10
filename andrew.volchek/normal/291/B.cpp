#include <cstdio>
#include <cstring>

char s[100005];
char t[100005];

int main()
{
    gets(s);
    int len = strlen(s);
    int clen = 0;
    bool q = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ' ')
        {
            if (q)
            {
                t[clen++] = s[i];
            }
            else
            {
                if (clen)
                {
                    t[clen] = 0;
                    printf("<%s>\n", t);
                    clen = 0;
                }
            }
        }
        else if(s[i] == '"')
        {
            if (q)
            {
                t[clen] = 0;
                printf("<%s>\n", t);
                clen = 0;
                q = false;
            }
            else
            {
                if (clen)
                {
                    t[clen] = 0;
                    printf("<%s>\n", t);
                    clen = 0;
                }
                q = true;
            }
        }
        else
        {
            t[clen++] = s[i];
        }
    }
    
    if (clen)
    {
        t[clen] = 0;
        printf("<%s>\n", t);
        clen = 0;
    }
    
    return 0;
}