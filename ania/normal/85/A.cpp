#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	if(n&1)
	{
		for(int i = 0; i < n-1; i++) printf("%c", 'a'+((i/2)&1)); printf("c\n");
		for(int i = 0; i < n-1; i++) printf("%c", 'a'+1-((i/2)&1)); printf("c\nf");
		for(int i = 0; i < n-1; i++) printf("%c", 'd'+((i/2)&1)); printf("\nf");
		for(int i = 0; i < n-1; i++) printf("%c", 'd'+1-((i/2)&1)); printf("\n");
	}
	else
	{
		for(int i = 0; i < n; i++) printf("%c", 'a'+((i/2)&1)); printf("\n");
		for(int i = 0; i < n; i++) printf("%c", 'a'+1-((i/2)&1)); printf("\nf");
		for(int i = 0; i < n-2; i++) printf("%c", 'd'+((i/2)&1)); printf("h\nf");
		for(int i = 0; i < n-2; i++) printf("%c", 'd'+1-((i/2)&1)); printf("h\n");

	}
}