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
	static final int mod=1000000007;
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int n=in.nextInt();
		int wr[]=new int[n];
		for(int i=0; i<n; i++)
			wr[i]=in.nextInt();
		int pro[]=new int[5];
		for(int i=0; i<5; i++)
			pro[i]=in.nextInt();
		long curs=0;
		long count[]=new long[5];
		for(int i=0; i<n; i++)
		{
			curs+=wr[i];
			while(curs>=pro[0])
			for(int j=4; j>=0; j--)
			{
				if(curs>=pro[j])
				{
					count[j]+=curs/pro[j];
					curs-=(curs/pro[j])*pro[j];
					break;
				}
			}
		}
		for(int i=0; i<5; i++)
			System.out.print(count[i]+" ");
		System.out.println("\n"+curs);
		System.out.println(ans);
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
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        
    }
}