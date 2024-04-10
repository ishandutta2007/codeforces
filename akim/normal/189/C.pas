var a,b:array[1..200000]of longint;
    s:int64;
    i,f,n:longint;
begin
 readln(n);s:=0;
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n do
  read(b[i]);
 i:=1;f:=1;
 while f<=n do
  if a[i]=b[f] then begin inc(i);inc(f);end else begin inc(f);inc(s);end;
 writeln(s);
end.