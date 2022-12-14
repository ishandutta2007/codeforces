var
 s:ansistring;
 a:array[1..4]of longint;
 b,c,n,m,su,k,i,j:longint;
begin
 for i:=1 to 4 do read(a[i]);
 readln;
 readln(s);
 m:=length(s);
 for i:=1 to m do
 begin
  c:=ord(s[i])-48;
  su:=su+a[c];
 end;
 writeln(su);
end.