var n,s1,s2,i:longint;
    log:boolean;
    s:string;
begin
 readln(n);s1:=0;s2:=0;
 readln(s);if n mod 2=0 then log:=true else log:=false;
 for i:=1 to n do
 begin
  case s[i] of 
  '0':begin writeln('NO');halt(0);end;
  '1':begin writeln('NO');halt(0);end;
  '2':begin writeln('NO');halt(0);end;
  '3':begin writeln('NO');halt(0);end;
  '4':begin 
       if (log) then 
       begin 
        if (n div 2<i) then s2:=s2+4 else s1:=s1+4;
       end 
       else 
       begin 
        if (n div 2<i)and(i<>n div 2+1) then s2:=s2+4;
        if (n div 2>=i)and(i<>n div 2+1) then s1:=s1+4; 
       end;
      end;
  '5':begin writeln('NO');halt(0);end;
  '6':begin writeln('NO');halt(0);end;
  '7':begin 
       if (log) then 
       begin 
        if (n div 2<i) then s2:=s2+7 else s1:=s1+7;
       end 
       else 
       begin 
        if (n div 2<i)and(i<>n div 2+1) then s2:=s2+7;
        if (n div 2>=i)and(i<>n div 2+1) then s1:=s1+7; 
       end;
      end;
  '8':begin writeln('NO');halt(0);end;
  '9':begin writeln('NO');halt(0);end;
  end;
 end;
 if s1=s2 then writeln('YES') else writeln('NO');
end.