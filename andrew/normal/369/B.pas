var
 a:array[1..1000] of longint;
 n,k,l,sk,r,sa,i,j:longint;
 x,md,dv:longint;
begin
 readln(n,k,l,r,sk,sa);
 x:=sa div k;


 for i:=1 to sa mod k do write(x+1,' ');
 for i:=sa mod k+1 to k do write(x,' ');
  sa:=sk-sa;
  k:=n-k;
 if k>0 then
 begin
 x:=sa div k;
 for i:=1 to k do a[i]:=x;

 for i:=1 to sa mod k do write(x+1,' ');
 for i:=sa mod k+1 to k do write(a[i],' ');
 end;
 readln;
end.