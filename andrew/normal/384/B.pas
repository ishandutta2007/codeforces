var
 a:array[0..1000,0..1000] of longint;
 li,lj,vaaa:array[0..1000] of longint;
 mjj,d,l,cv,ch,k,mj,m,n,i,j,b,s,v:longint;
begin
 readln(n,cv,k) ;

 for i:=1 to n do
  for j:=1 to cv do
  begin
   read(a[j,i]);
  end;

 l:=(cv*(cv-1) div 2);
 d:=l;
 writeln(l);
 for i:=1 to l do
 begin
  for j:=i to cv-1 do
  begin
  if l=0 then break;
   inc(mjj);
   if k=0 then writeln(mjj,' ',mjj+1);
   if k=1 then writeln(mjj+1,' ',mjj);
   dec(l);
  end;
  mjj:=0;
  if l=0 then break;
 end;
end.