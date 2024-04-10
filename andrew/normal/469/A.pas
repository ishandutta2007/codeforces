var
 a:Array[1..100]of longint;
 k,m,n,i,j:longint;
begin
 readln(n);
 read(k);
 for i:=1 to k do
 begin
  read(j);
  inc(a[j]);
 end;       readln;
 read(k);
 for i:=1 to k do
 begin
  read(j);
  inc(a[j]);
 end;       readln;
 for i:=1 to n do if a[i]=0 then
 begin
  writeln('Oh, my keyboard!');
  halt;
 end;
 writeln('I become the guy.');
end.