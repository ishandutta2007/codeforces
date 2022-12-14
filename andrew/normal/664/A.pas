var
 s1,s2,s:string;
begin
 readln(s);
 s1:=copy(s,1,pos(' ',s)-1);
 s2:=copy(s,pos(' ',s)+1,length(s));
 if s1<>s2 then writeln(1) else writeln(s1);
end.