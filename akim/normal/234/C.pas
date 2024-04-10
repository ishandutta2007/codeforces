var a:array[0..100000,1..3]of longint;
    i,n,k,min:longint;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(n);
 for i:=1 to n do
 begin
  read(k);
  a[i]:=a[i-1];
  if k>0 then inc(a[i,1]);
  if k<0 then inc(a[i,2]);
  if k=0 then inc(a[i,3]);
 end;
 min:=1000000;
 for i:=1 to n-1 do
  if (a[i,1]+a[i,3])+(a[n,2]-a[i,2]+a[n,3]-a[i,3])<min then min:=(a[i,1]+a[i,3])+(a[n,2]-a[i,2]+a[n,3]-a[i,3]);
 writeln(min);
 close(input);close(output);
end.