var
 s,s2:ansistring;
 v1,l1,l2,su1,su2,su3:longint;
 k,d1,d2,xn,n,i,j,r,dop:longint;
begin
 readln(n);
 readln(s);
 v1:=1;
 for i:=1 to n do
 begin
  if s[i]='.' then inc(su1);
  if (s[i]='.')and(l2>0) then inc(su3);
  if s[i]='R' then inc(l2);
  if s[i]='L' then inc(l1);
  if (l1>0) then  begin su1:=0;  end;
  if (l2=1)and(v1=1) then begin su2:=su2+su1; su1:=0; v1:=0;  end;
  if (l1=1)and(l2=0) then l1:=0;
  if (l1=l2)and(l1<>0) then
  begin
   l1:=0;
   l2:=0;
   v1:=1;
   d1:=0;
   su2:=su2+(su3 mod 2);
   su3:=0;
  end;
 end;
 if l2=0 then dop:=su1;
 writeln(su2+dop);
end.