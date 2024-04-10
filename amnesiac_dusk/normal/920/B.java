import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		Reader in=new Reader();
		int t=in.nextInt();
		while(t-->0)
		{
			int n=in.nextInt();
			int a[][]=new int[n][2];
			for(int i=0; i<n; i++)
			{
				a[i][0]=in.nextInt();
				a[i][1]=in.nextInt();
			}
			Queue<Integer> ho=new LinkedList<Integer>();
			int te=0,te1=0;
			for(int i=1;; i++)
			{
				while(te!=n&&a[te][0]==i)
				{
					ho.add(a[te][1]);
					te++;
				}
			//	System.out.println(te);
				if(!ho.isEmpty())
				{
					te1=ho.poll();
					while(te1<i&&(!ho.isEmpty()))
					{
					//	System.out.println("hola");
						ans1.append("0 ");
						te1=ho.poll();
					}
					if(te1<i)
						ans1.append("0 ");
					else
						ans1.append(i+" ");
				}
				if(te==n&&ho.isEmpty())
					break;
			}
			System.out.println(ans1);
			ans1=new StringBuilder();
		}
		/*int n=in.nextInt();
		int a[]=new int[n];
		for(int i=0; i<n; i++)
			a[i]=in.nextInt();
		String c=in.next();
		int max1=0,max2,min1,min2;
		for(int i=0; i<n; i++)
		{
			if(c.charAt(i)=='0')
			{
				min2=a[i];
				
			}
		}*/
		
	}
	static StringBuilder ans1=new StringBuilder();
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
            byte[] buf = new byte[655350]; // line length
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