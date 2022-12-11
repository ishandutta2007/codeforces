var a:array[1..100000]of string;
    k,i,s,l,f:longint;c:char;
begin
 readln(k);
 for i:=1 to k do
  readln(a[i]);
 l:=length(a[1]);
 for i:=1 to l do
 begin
  c:=a[1][i];
  for f:=2 to k do
   if c<>a[f][i] then begin writeln(s);halt(0);end;
  inc(s);
 end;
end.