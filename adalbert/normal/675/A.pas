var
a,b,c:int64;
begin
readln(a,b,c);
if ((b>a) and (c<0))    or ((b<a)and (c>0))  then writeln('NO')else
if (c=0) and (a=b) then writeln('YES') else
if (c=0) and (a<>b) then writeln('No') else
if (abs(b-a) mod (abs(c))=0) then writeln('YES') else writeln('NO');
end.