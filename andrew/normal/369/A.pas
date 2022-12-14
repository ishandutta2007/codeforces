var
 a:array [-999..9999] of longint;
 b,d:real;
 c,i,n,m,k,s:longint;
begin
 readln(n,m,k);
 b:=m;
 d:=k;
 s:=0;
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i]=1 then b:=b-1;
  if a[i]=2 then d:=d-1;

  if (b<0) or (d<0) then
  begin
   if (b<0) and (a[i]=1) then b:=b+1;
   s:=s+1;
  end;

  if (d<0) and (b>0) then
  begin
   b:=b-1;
   s:=s-1;
   d:=d+1;
  end;
 end;
 writeln(s);
 readln;
end.

(*
1-m- glubokie
2-k-ploskie
*)