var
 a,b,c:longint;
begin
 readln(a,b);
 if (abs(a-b)>1)or(a+b=0) then writeln('NO')else writeln('YES');
end.