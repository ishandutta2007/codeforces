var s1,s2:string;
    i:longint;
    f,t:boolean;
begin
readln (s1);
readln (s2);
if length (s1)<>length (s2) then write ('NO')
    else
        begin
          if s1=s2 then write ('YES')
                  else
                      begin
                       f:=false;
                       t:=false;
                       for i:=1 to length (s1) do if s1[i]='1' then f:=true;
                       for i:=1 to length (s2) do if s2[i]='1' then t:=true;
                      
                       if f and t and (length (s1)<>1) then write ('YES')
                                  else write ('NO')
                      end;
              
                             
        end;
end.