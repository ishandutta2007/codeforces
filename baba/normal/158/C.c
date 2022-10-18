#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}


void menu()
{
	printf("1. Push \n2. Pop\n3. Top\n0. Exit\n");
}


int main()
{
	int n;
	din(n);
	int i;
	char currdir[10000];
	currdir[0]='/';
	currdir[1]='\0';
	int clen=1;
	for(i=0;i<n;i++)
	{
		char command[10];
		scanf("%s",command);
		if(!strcmp(command,"pwd"))
			printf("%s\n",currdir);
		else
		{
			char path[210];
			scanf("%s",path);
			int j;
			
			if(path[0]=='/')
			{
				currdir[0]='\0';
				clen=0;
			}



			char word[100];
			word[0]='\0';
			int wordlen=0;
			for(j=0;;j++)
			{
				if(path[j]=='/' || path[j]=='\0')
				{
					if(!strcmp(word,".."))
					{
						int k;
						for(k=clen-2;currdir[k]!='/';k--);
						currdir[k]='/';
						currdir[k+1]='\0';
						clen = k+1;
					}
					else
					{
						strcat(currdir,word);
						clen = clen + strlen(word);
						currdir[clen]='/';
						currdir[clen+1]='\0';
						clen++;
					}
					wordlen=0;
					if(path[j]=='\0')
						break;
				}
				else
				{
					word[wordlen++]=path[j];
					word[wordlen]='\0';
				}
			}
		}
	}

			



	return 0;
}