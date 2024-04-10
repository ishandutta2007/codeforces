var k,a,b,v,w,u,aa,aaa,l:int64;
begin
 read (k,a,b,v);
 l:=b div (k-1);
 u:=k*v*l;
 if a<=k*v*l then write ((a-1) div (v*k)+1)
            else
            begin
             aa:=a-k*v*l;
             w:=b-l*(k-1);
             if aa<=(w+1)*v then write (l+1)
                            else
                            begin
                             aaa:=aa-(w+1)*v;
                             write (l+2+(aaa-1) div v);
                            end;
            end;
end.