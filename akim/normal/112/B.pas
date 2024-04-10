var a,b,c:longint;
begin
 readln(a,b,c);
 if (a div 2=b)and(a div 2=c)or(a div 2+1=b)and(a div 2=c)or(a div 2=b)and(a div 2+1=c)or(a div 2+1=b)and(a div 2+1=c) then writeln('NO') else writeln('YES');
end.