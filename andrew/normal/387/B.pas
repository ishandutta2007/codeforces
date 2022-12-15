var
 a,b:array[0..100000] of longint;
 n,m,c,k,s,i,j:longint;
begin
 readln(m,n);
 for i:=1 to m do read(a[i]);
 for i:=1 to n do read(b[i]);

 for i:=1 to n do for j:=1 to n do if b[j]>b[i] then
 begin
  c:=b[i];
  b[i]:=b[j];
  b[j]:=c;
 end;


 for i:=1 to n do
 for j:=1 to m do if (b[i]>=a[j]) then

  begin
   inc(s);
   a[j]:=maxlongint;
   break;
  end;
 if (n=0) and (m=0) then writeln(s);
 writeln(m-s);

end.