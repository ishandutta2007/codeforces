import java.io.*;
import java.util.*;
/*
 * 	Author: rahuldugar
 * 	Heart beats fast
 * 		Colors and promises
 * 			How to be brave
 * 				How can I love when I am afraid to fall...
 */
public class Main
{
	static int g(int a)
	{
		int b=1;
		while(a>0)
		{
			if(a%10!=0)
				b*=a%10;
			a/=10;
		}
		return b;
	}
	static int b[];
	static final int mod=1000000007;
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int q=in.nextInt();
		b=new int[1000001];
		int pres[][]=new int[1000001][10];
		for(int i=1; i<1000001; i++)
		{
			b[i]=g(i);
			if(b[i]>=10)
				b[i]=b[b[i]];
			pres[i][b[i]]++;
			for(int j=0; j<10; j++)
				pres[i][j]+=pres[i-1][j];
		}
		while(q-->0)
		{
			int l=in.nextInt(),r=in.nextInt(),k=in.nextInt();
			System.out.println(pres[r][k]-pres[l-1][k]);
		}
	}
	static StringBuilder ans=new StringBuilder();
	static String pr(String a, long b)
	{
		String c="";
		while(b>0)
		{
			if(b%2==1)
				c=c.concat(a);
			a=a.concat(a);
			b>>=1;
		}
		return c;
	}
	static class Reader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public Reader() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
    }
}