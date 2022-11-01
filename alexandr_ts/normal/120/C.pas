var a:array[1..100]of longint;

    n,i,k,sum:longint;

begin

 assign(input,'input.txt');

 assign(output,'output.txt');

 reset(input);

 rewrite(output);

 read(n,k);

 for i:=1 to n do

   read(a[i]);

 for i:=1 to n do

   if a[i]>k*3 then

     inc(sum,(a[i]-k*3))

   else

     inc(sum,(a[i]mod k));

 write(sum);

 close(input);

 close(output);

end.