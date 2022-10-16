import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int m=in.nextInt();
		int n=in.nextInt();
		int k=in.nextInt();
		int[][] a=new int[n*m+1][2];
		for(int i=0; i<n/2; i++)
		{
			for(int j=1; j<=m; j++)
			{
				a[2*i*m+j][0]=j;
				a[2*i*m+j][1]=2*i+1;
			}
			for(int j=1; j<=m; j++)
			{
				a[(2*i+1)*m+j][0]=m-j+1;
				a[(2*i+1)*m+j][1]=2*i+2;
			}
		}
		if(n%2==1)
		{
			for(int i=1; i<=m; i++)
			{
				a[(n-1)*m+i][0]=i;
				a[(n-1)*m+i][1]=n;
			}
		}
		int p=1;
		for(int i=0; i<(k-1); i++)
		{
			ans.append("2 "+a[p][0]+" "+a[p][1]+" "+a[p+1][0]+" "+a[p+1][1]+"\n");
			p+=2;
		}
		ans.append((n*m-2*k+2)+" ");
		for(int i=p; i<=n*m;i++)
			ans.append(a[i][0]+" "+a[i][1]+" ");
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
	static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
        StringTokenizer st;
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        } 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public String next() throws IOException
        {
        	while(st==null||!st.hasMoreElements())
        	{
        		try
        		{
        			st=new StringTokenizer(readLine());
        		}
        		catch(IOException e)
        		{
        			e.printStackTrace();
        		}
        	}
        	return
        			st.nextToken();
        }
        public String readLine() throws IOException
        {
            byte[] buf = new byte[65535]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
        public long nextlong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
}