var
 s1,s2:ansistring;
  k,d1,d2,xn,n,i,j,r,s:longint;
begin
 d1:=2;
 d2:=2;
 readln(n);
 r:=67;
 if n mod 2=0 then writeln(n*n div 2) else writeln(n*n div 2+1);
{ for i:=1 to n do
 begin
  if i mod 2=0 then d1:=1 else d1:=2;
  k:=r;
  if d2 mod 2=0 then r:=46 else r:=67;
  inc(d2);
  for j:=1 to n do
  begin

   write(chr(k));
   if d1 mod 2=0 then k:=46 else k:=67;

   inc(d1);

  end;    }
  for i:=1 to n do if i mod 2=1 then s1:=s1+'C' else s1:=s1+'.';
  for i:=1 to n do if i mod 2=1 then s2:=s2+'.' else s2:=s2+'C';
  for i:=1 to n do if i mod 2=1 then writeln(s1) else writeln(s2);
end.

{   67-C
    46-.
}